#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
const int S=26;

int n,q,len,tp,l,r;
char s[N],t[N],ch;
bitset <N> c[S],ans;

int main(){
	scanf("%s%d",s,&q),n=strlen(s);
	for(int i=0;i<n;i++)c[s[i]-'a'][i]=1;
	while(q--){
		scanf("%d%d",&tp,&l),l--;
		if(tp==1)scanf("%s",&ch),c[s[l]-'a'][l]=0,c[(s[l]=ch)-'a'][l]=1;
		else{
			scanf("%d%s",&r,t),r--,len=strlen(t),ans.set();
			for(int i=0;i<len;i++)ans&=c[t[i]-'a']<<len-i-1;
			cout<<max(0,(int)((ans>>l+len-1).count()-(ans>>r+1).count()))<<"\n";
		}
	}
	return 0;
}