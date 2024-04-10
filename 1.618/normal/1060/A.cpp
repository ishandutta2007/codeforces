#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair

using namespace std;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
typedef long long ll;
typedef pair<int,int> P;
string s;
int cnt[15];
int n;
int main(){
	cin >> n;
	cin >> s;
	for(int i=0;i<(int)s.size();i++) cnt[s[i] - '0']++;
	printf("%d\n",min(n / 11,cnt[8]));
	return 0;
}