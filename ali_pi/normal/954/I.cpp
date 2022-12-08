#include<bits/stdc++.h>
using namespace std;

const int MAXN=125e3+5;

int P[6];

int fipar(int D) {
	if (P[D]!=P[P[D]]) {
		P[D]=fipar(P[D]);
	}
	
	return P[D];
}

void gabung(int aa,int bb) {
	int x, y;
	x=fipar(aa);
	y=fipar(bb);
	
	P[x]=y;
	
	return;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	char S[MAXN], T[MAXN];
	cin>>S>>T;
	int LS, LT;
	LS=strlen(S);
	LT=strlen(T);
	bool edge[6][6];
	int i;
	for (i=0;i<LS;i++) {
		S[i]-='a';
	}
	for (i=0;i<LT;i++) {
		T[i]-='a';
	}
	for (i=LT;i<=LS;i++) {
		int j, k;
		for (j=0;j<6;j++) {
			P[j]=j;
			for (k=0;k<6;k++) {
				edge[j][k]=0;
			}
		}
		for (j=0;j<LT;j++) {
			edge[S[i-LT+j]][T[j]]=1;
		}
		for (j=0;j<6;j++) {
			for (k=0;k<6;k++) {
				if (edge[j][k]) {
					gabung(j,k);
				}
			}
		}
		int ans;
		ans=6;
		for (j=0;j<6;j++) {
			if (P[j]==j) {
				ans--;
			}
		}
		cout<<ans<<' ';
	}
	cout<<'\n';
	return 0;
}