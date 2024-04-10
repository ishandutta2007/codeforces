
// Problem : D. Jeff and Removing Periods
// Contest : Codeforces - Codeforces Round #204 (Div. 1)
// URL : https://codeforces.com/problemset/problem/351/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
const int B = 475;
int arr[100005];
int srt[100005];
int ans[100005];
int lft[100005], rht[100005];
vector<int> pos[100005];
int idx[100005];
int bad[100005];
int fre[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];	
		pos[arr[i]].emplace_back(i);
		idx[i] = pos[arr[i]].size();
	}
	cin >> Q;
	for(int i = 1; i<=Q; i++){
		cin >> lft[i] >> rht[i];
		srt[i] = i;
	}
	sort(srt+1, srt+1+Q, [](int a, int b){
		if(lft[a]/B == lft[b]/B && rht[a] != rht[b]){
			return rht[a] < rht[b];
		}
		return lft[a] < lft[b];
	});
	int frecnt = 0, badcnt = 0;
	for(int i = 1, l = 1, r = 0; i<=Q; i++){
		int q = srt[i];
		while(r < rht[q]){
			r++;
			frecnt += !fre[arr[r]];
			fre[arr[r]]++;
			if(idx[r] >= 3 && l <= pos[arr[r]][idx[r]-3] && pos[arr[r]][idx[r]-1] + pos[arr[r]][idx[r]-3] != 2 * pos[arr[r]][idx[r]-2]){
				badcnt += !bad[arr[r]];
				bad[arr[r]]++;
			}
		}
		while(r > rht[q]){
			fre[arr[r]]--;
			frecnt -= !fre[arr[r]];
			if(idx[r] >= 3 && l <= pos[arr[r]][idx[r]-3] && pos[arr[r]][idx[r]-1] + pos[arr[r]][idx[r]-3] != 2 * pos[arr[r]][idx[r]-2]){
				bad[arr[r]]--;				
				badcnt -= !bad[arr[r]];
			}		
			r--;	
		}
		while(l < lft[q]){
			fre[arr[l]]--;
			frecnt -= !fre[arr[l]];
			if(idx[l]+2 <= pos[arr[l]].size() && r >= pos[arr[l]][idx[l]+1] && pos[arr[l]][idx[l]-1] + pos[arr[l]][idx[l]+1] != 2 * pos[arr[l]][idx[l]]){
				bad[arr[l]]--;
				badcnt -= !bad[arr[l]];
			}			
			l++;
		}
		while(l > lft[q]){
			l--;
			frecnt += !fre[arr[l]];
			fre[arr[l]]++;
			if(idx[l]+2 <= pos[arr[l]].size() && r >= pos[arr[l]][idx[l]+1] && pos[arr[l]][idx[l]-1] + pos[arr[l]][idx[l]+1] != 2 * pos[arr[l]][idx[l]]){
				badcnt += !bad[arr[l]];
				bad[arr[l]]++;
			}
		}
		ans[q] = frecnt + (badcnt == frecnt);
	}
	for(int q = 1; q<=Q; q++){
		cout << ans[q] << "\n";
	}
}