#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>

#define ll long long
#define pb push_back

const int maxn = 1e5 + 100;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'a' or s[i] == 'e' or s[i] == 'o' or s[i] == 'u' or s[i] == 'i')
			cnt ++;
		if (s[i] == '1' or s[i] == '3' or s[i] == '5' or s[i] == '7' or s[i] == '9')
			cnt ++;
	}
	cout << cnt << endl;
}