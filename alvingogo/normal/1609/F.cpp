#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

long long calc(vector<pair<long long,int> > v){
	int n=v.size();
	if(n==0){
		return 0;
	}
	if(n==1){
		return 1;
	}
	int l=(n-1)/2;
	long long ans=0;
	vector<pair<long long,int> > b(n),s(n);
	b[l]=s[l]=v[l];
	if(l+1<n){
		b[l+1]=s[l+1]=v[l+1];
	}
	for(int i=l-1;i>=0;i--){
		b[i]=max(b[i+1],v[i]);
		s[i]=min(s[i+1],v[i]);
	}
	for(int i=l+2;i<n;i++){
		b[i]=max(b[i-1],v[i]);
		s[i]=min(s[i-1],v[i]);
	}
	//LBLS
	{
		int nw=0,w=l+1;
		for(int i=l;i>=0;i--){
			while(w<n && b[w].fs<=b[i].fs && s[w].fs>=s[i].fs){
				w++;
				nw++;
			}
			if(b[i].sc==s[i].sc){
				ans+=nw;
			}
		}
	}
	//RBRS
	{
		int nw=0,w=l;
		for(int i=l+1;i<n;i++){
			while(w>=0 && b[w].fs<=b[i].fs && s[w].fs>=s[i].fs && !(b[w].fs==b[i].fs && s[w].fs==s[i].fs)){
				w--;
				nw++;
			}
			if(b[i].sc==s[i].sc){
				ans+=nw;
			}
		}
	}
	//LBRS
	{
		vector<int> ch(64);
		int bg=l+1,sm=l+1;
		for(int i=l;i>=0;i--){
			while(bg<n && b[bg].fs<b[i].fs){
				ch[s[bg].sc]++;
				bg++;
			}
			while(sm<bg && s[sm].fs>=s[i].fs){
				ch[s[sm].sc]--;
				sm++;
			}
			ans+=ch[b[i].sc];
		}
	}
	//RBLS
	{
		vector<int> ch(64);
		int bg=l,sm=l;
		for(int i=l+1;i<n;i++){
			while(bg>=0 && b[bg].fs<b[i].fs){
				ch[s[bg].sc]++;
				bg--;
			}
			while(sm>bg && s[sm].fs>=s[i].fs){
				ch[s[sm].sc]--;
				sm--;
			}
			ans+=ch[b[i].sc];
		}
	}
	vector<pair<long long,int> > d;
	for(int i=0;i<=l;i++){
		d.push_back(v[i]);
	}
	ans+=calc(d);
	d.clear();
	for(int i=l+1;i<n;i++){
		d.push_back(v[i]);
	}
	ans+=calc(d);
	return ans;
}
int main(){
	AquA;
    int n;
    cin >> n;
    vector<pair<long long,int> > v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].fs;
		v[i].sc=__builtin_popcountll(v[i].fs);
    }
    cout << calc(v) << "\n";
	return 0;
}