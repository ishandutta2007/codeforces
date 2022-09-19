#include <bits/stdc++.h>

/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
*/
using namespace std;

typedef string str;
const int Maxn = 2e5 + 3;
const int SQ = 1700;

int n, ps[Maxn];
long long ans;

int main(){
    str s;
    cin >> s;
	/*s = "";
	for(int i = 0; i < 200000; i++){
		if(rand() & 1) s += '1';
		else s += '0';
	}*/
	n = s.size();
    for(int i = 1; i <= n; i ++) ps[i] = ps[i - 1] + (s[i - 1] == '1');
    
    int p1, p2;
	for(int k = 1; k <= SQ; k ++){
        p1 = 1; p2 = 1;
        for(int i = 1; i <= n; i ++){
            while((p2 <= n) && (ps[p2] - ps[i - 1] <= k)) p2 ++;
			while((p1 <= n) && (ps[p1] - ps[i - 1] < k)) p1++;
			if(p1 > n) break;
        	ans += (p2-i)/k - (p1-i)/k;
			//cerr << ans << " " << p1 << " " << p2 << '\n';
		}
    }
	int p3;
    int it = n / SQ + 2;
	for(int k = 1; k <= it; k++){
        vector<pair<int, int>> P;
		for(int i = 0; i <= n; i ++){
            P.emplace_back(ps[i] * k - i, ps[i]);
        }
        sort(P.begin(), P.end());
        for(int i = 0; i < P.size(); i){
            p3 = i;
            while((p3 < n + 1) && (P[i].first == P[p3].first)) p3++;
            p2 = i;
            for(int j = i; j < p3; j++){
                while((p2 < p3) && (P[p2].second - P[j].second <= SQ)) p2++;
                ans += p3 - p2;
			}
            i = p3;
        }
    }
    cout << ans;
    return 0;
}