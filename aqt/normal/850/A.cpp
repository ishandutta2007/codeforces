
// Problem : A. Five Dimensional Points
// Contest : Codeforces - Codeforces Round #432 (Div. 1, based on IndiaHacks Final Round 2017)
// URL : https://codeforces.com/contest/850/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct point{
	int a, b, c, d, e;
};

int N;
vector<int> v;
const long double PI = acos(0);

int dot(point a, point b){
	return a.a * b.a + a.b * b.b + a.c * b.c + a.d * b.d + a.e * b.e;
}

point sub(point a, point b){
	return {b.a-a.a, b.b-a.b, b.c-a.c, b.d-a.d, b.e-a.e};
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	if(N > 50){
		cout << 0 << "\n";
		return 0;
	}
	vector<point> v;
	v.push_back({0, 0, 0, 0, 0});
	for(int i = 1; i<=N; i++){
		point p;
		cin >> p.a >> p.b >> p.c >> p.d >> p.e;
		v.push_back(p);
	}
	vector<int> ans;
	for(int i = 1; i<=N; i++){
		bool b = 1;
		for(int j = 1; j<=N; j++){
			for(int k = 1; k<=N; k++){
				if(j != k && i != j && i != k){
					auto p = sub(v[i], v[j]), q = sub(v[i], v[k]);
					//cout << acos(dot(p, q)/sqrt(dot(p, p))/sqrt(dot(q, q))) << "\n";
					if(acos(dot(p, q)/sqrt(dot(p, p))/sqrt(dot(q, q))) < PI){
						b = 0;
					}
				}
			}
		}
		if(b){
			ans.push_back(i);
		}
	}
	cout<< ans.size() << "\n";
	for(int n : ans){
		cout << n << "\n";
	}
}