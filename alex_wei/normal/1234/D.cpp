#include<bits/stdc++.h>
using namespace std;
string s;
int b[28][100005],n,q;
int lowbit(int x){return x&-x;}
void add(int id,int pos,int num){while(pos<=n)b[id][pos]+=num,pos+=lowbit(pos);}
int sum(int id,int pos){int ans=0;while(pos)ans+=b[id][pos],pos-=lowbit(pos);return ans;}
int main()
{
	cin>>s>>q,n=s.size();
	for(int i=1;i<=n;i++)
		add(s[i-1]-'a',i,1);
	for(int i=1;i<=q;i++){
		int op;
		cin>>op;
		if(op==1){
			int pos;
			char ch;
			cin>>pos>>ch;
			add(ch-'a',pos,1);
			add(s[pos-1]-'a',pos,-1);
			s[pos-1]=ch;
		}
		else{
			int l,r;
			cin>>l>>r;
			int pd=0;
			for(int i=0;i<26;i++)
				if(sum(i,r)-sum(i,l-1))
					pd++;
			cout<<pd<<endl;
		}
	}
    return 0;
}