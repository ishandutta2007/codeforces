#include<bits/stdc++.h>
using namespace std;
vector<int> buildZ(const string& T){
	vector<int> z(T.size());
	int L=0,R=0;
	for(int i=1;i<T.size();i++){
		if(i>=R) z[i]=0;
		else z[i]= min(z[i-L],R-i);
		while(i+z[i]<T.size() && T[z[i]]==T[i+z[i]]) z[i]++;
		if(i+z[i]>R) L=i,R=i+z[i];
	}
	return z;
}
vector<int> runZ(const string& S, const string& T, vector<int>& z){
	vector<int> ret(S.size());
	int L=0,R=0;
	for(int i=0;i<S.size();i++){
		if(i>=R) ret[i]=0;
		else ret[i] = min(z[i-L],R-i);
		while(i+ret[i]<z.size() && T[ret[i]]==S[i+ret[i]]) ret[i]++; 
		if(i+ret[i]>R) L=i,R=i+ret[i];
	}
	return ret;
}
int main(){
	string S,T,rS;
	getline(cin,S);
	getline(cin,T);
	if(S.size()!=T.size()){
		puts("-1 -1");
		exit(0);
	}
	rS=S;
	reverse(rS.begin(),rS.end());
	vector<int> zT=buildZ(T);
	vector<int> zToS=runZ(S,T,zT);
	vector<int> zrS=buildZ(rS);
	vector<int> zrSoT=runZ(T,rS,zrS);
	vector<int> mr(S.size());
	for(int i=0;i<S.size();i++){
		if(i+zrSoT[i]==S.size()) zrSoT[i]--;
		mr[i]=i+zrSoT[i];
		if(i) mr[i]=max(mr[i],mr[i-1]);
	}
	vector<int> gf(S.size());
	for(int i=1;i<S.size();i++){
		gf[i]=lower_bound(mr.begin(),mr.begin()+zToS[i]+1,S.size()-i)-mr.begin();
	}
	int ai=-1,aj=-1;
	for(int i=1;i<S.size();i++){
		if(rS[S.size()-i]!=T[T.size()-i]) break;
		if(gf[i]<=zToS[i]) ai=i-1,aj=i+gf[i];
	}
	printf("%d %d\n",ai,aj);
	return 0;
}