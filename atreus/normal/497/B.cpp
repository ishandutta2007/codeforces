/**
 *    author:  Atreus
 *    created: 22.01.2019
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
int fp[maxn], sp[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		fp[i] = fp[i - 1] + (x == 1);
		sp[i] = sp[i - 1] + (x == 2);
	}
	vector<pair <int, int> > answer;
	for (int t = 1; t <= n; t++){
		int sfp = 0, ssp = 0;
		int now = 1, lastsetwon;
		bool what = 1;
		while (now <= n){
			int lo = now - 1, hi = n + 1;
			while (hi - lo > 1){
				int mid = (hi + lo) >> 1;
				if (fp[mid] - fp[now - 1] >= t or sp[mid] - sp[now - 1] >= t)
					hi = mid;
				else
					lo = mid;
			}
			if (hi == n + 1){
				what = 0;
				break;
			}
			if (fp[hi] - fp[now - 1] >= t)
				lastsetwon = 1;
			else
				lastsetwon = 2;
			sfp += (fp[hi] - fp[now - 1] >= t);
			ssp += (sp[hi] - sp[now - 1] >= t);
			now = hi + 1;
		}
		if (what){
			if (sfp > ssp and lastsetwon == 1)
				answer.push_back({max(sfp, ssp), t});
			if (sfp < ssp and lastsetwon == 2)
				answer.push_back({max(sfp, ssp), t});
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (auto it : answer)
		cout << it.first << " " << it.second << '\n';
}