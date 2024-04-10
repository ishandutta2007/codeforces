//============================================================================
// Name        : q1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
#define fori(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=1;i<n;i++)
#define fort(i,m,n) for(int i=m;i<n;i++)
#define maxi 998244353
#define mod(x) ((x)%maxi)
typedef long long lol;
typedef vector<int> veci;
typedef vector<lol> vecl;
string reverse(string a){
	string b;
	while(a.size()){
		b.push_back(a.back());
		a.pop_back();
	}
	return b;
}
#define num 62
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<string>> arr(11);
	fori(i,n){
		string line;
		cin >> line;
		arr[line.size()].push_back(line);
		arr[line.size()].push_back(reverse(line));
	}
	lol ans=0;
	vector<int> mapit(256);
	fori(i,26){
		mapit['a'+i]=i;
		mapit['A'+i]=i+26;
	}
	fori(i,10){
		mapit['0'+i]=52+i;
	}
	lol triple[num][num][num];
	fort(l,3,11){
		vector<vecl> doble(num,vecl(num));
		sort(arr[l].begin(),arr[l].end());
		fori(i,arr[l].size()){
			if(i>0&&arr[l][i]==arr[l][i-1]){
				continue;
			}
			doble[mapit[arr[l][i][0]]][mapit[arr[l][i].back()]]++;
		}
		fori(a,num){
			fort(b,a,num){
				fort(c,b,num){
					triple[a][b][c]=0;
					fori(d,num){
						lol cur=1;
						cur=mod(cur*doble[a][d]);
						cur=mod(cur*doble[b][d]);
						cur=mod(cur*doble[c][d]);
						triple[a][b][c]=mod(cur+triple[a][b][c]);
					}
				}
			}
		}
		fori(a,num){
			fort(b,a,num){
				fort(c,b,num){
					fort(d,c,num){
						lol cur=24;
						if(a==b){
							cur/=2;
							if(b==c){
								cur/=3;
								if(c==d){
									cur/=4;
								}
							}else{
								if(c==d){
									cur/=2;
								}
							}
						}else{
							if(b==c){
								cur/=2;
								if(c==d){
									cur/=3;
								}
							}else{
								if(c==d){
									cur/=2;
								}
							}
						}
						cur=mod(cur*triple[a][b][c]);
						cur=mod(cur*triple[a][b][d]);
						cur=mod(cur*triple[a][c][d]);
						cur=mod(cur*triple[b][c][d]);
						ans = mod(ans+cur);
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}