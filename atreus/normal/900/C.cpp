#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <stack>

using namespace std;

stack <int> s;
const int maxn = 1e5 + 500;
int a[maxn], big[maxn], ans[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		big[i] = max(big[i - 1], a[i]);
	for (int i = 1; i <= n; i++){
		while (!s.empty() && a[s.top()] < a[i])
			s.pop();
		if (s.empty()){
			ans[a[i]] --;
			s.push(i);
			continue;
		}
//		cout << a[i] << " " << s.top() << " " << big[s.top() - 1] << endl;
		if (s.size() == 1 && big[s.top() - 1] < a[i])
			ans[a[s.top()]] ++;
		s.push(i);
	}
	int k = -5, inx = 1;
	for (int i = 1; i <= n; i++){
		if (k < ans[i]){
			inx = i;
			k = ans[i];
		}
	}
	cout << inx << endl;
}