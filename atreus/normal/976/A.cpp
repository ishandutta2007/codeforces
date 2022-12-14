#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
const int maxn = 111;
long long minn[maxn][maxn], c[maxn], p[maxn][maxn], dp[maxn][maxn][maxn];;
int main (){
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '1'){
			cout << 1;
			for (int j = i + 1; j < s.size(); j++){
				if (s[j] == '0')
					cout << 0;
			}
			break;
		}
		else if (i == s.size() - 1)
			cout << s << endl;
	}
}