
// Problem : C. Nezzar and Nice Beatmap
// Contest : Codeforces - Codeforces Round #698 (Div. 1)
// URL : https://codeforces.com/contest/1477/problem/C
// Memorsecond Limit : 512 MB
// Time Limit : 2000 ms
// Powered bsecond CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;


int N;
pair<long long, long long> arr[5005];
int perm[5005];

long long dist2(int a, int b){
	long long dfirst = arr[a].first - arr[b].first;
	long long dsecond = arr[a].second - arr[b].second;
	return dfirst * dfirst + dsecond * dsecond;
}

bool isObtuse(int a, int b, int c){
	unsigned long long ab = dist2(a, b);
	unsigned long long bc = dist2(b, c);
	unsigned long long ac = dist2(a, c);
	//cout << a << " " << b << " " << c << " " << (ab + bc <= ac) << "\n";
	return ab + bc <= ac;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i].first;
		cin >> arr[i].second;
		perm[i] = i;
	}
	for(int i = 1; i <= N; i++){
		for(int j = i; j - 2 > 0; j--){
			if(isObtuse(perm[j-2], perm[j-1], perm[j])){
				swap(perm[j-1], perm[j]);
			}
			else{
				break;
			}
		}
	}
	for(int i = 1; i <= N; i++){
		cout << perm[i] << " ";
	}
}