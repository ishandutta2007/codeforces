#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 52 + 10;

vector<int> ops[maxn];
int a[maxn], b[maxn], pos[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int answer = 0;
	for (int i = 1; i <= n; i++){
		bool flag = 1;
		for (int j = 1; j <= n; j++){
			if (a[j] != j)
				flag = 0;
			pos[a[j]] = j;
		}
		if (flag)
			break;
		int idx = -1;
		for (int i = n-1; i >= 1; i--)
			if (pos[i] > pos[i+1])
				idx = i;
		vector<int> now;
		if (pos[idx+1] > 1)
			now.push_back(pos[idx+1]-1);
		for (int j = pos[idx+1]; j <= pos[idx]; j++){
			if (j-pos[idx+1] != a[j]-(idx+1)){
				now.push_back(j-pos[idx+1]);
				now.push_back(pos[idx]-j+1);
				break;
			}
		}
		if (pos[idx] != n)
			now.push_back(n-pos[idx]);
		ops[answer] = now;
		answer ++;
		int ptr = n, me = 1;
		for (auto d : now){
			for (int j = ptr-d+1; j <= ptr; j++)
				b[j] = a[me++];
			ptr -= d;
		}
		for (int i = 1; i <= n; i++)
			a[i] = b[i];
	}
	cout << answer << '\n';
	for (int i = 0; i < answer; i++){
		cout << ops[i].size() << " ";
		for (auto it : ops[i])
			cout << it << " ";
		cout << '\n';
	}
}