#include<bits/stdc++.h>
using namespace std;
int T,n,q,l[200003],r[200003],sz=500; 
int dat[403],a[200003],cnt[403];
string s,t;
int calc(int l){int CNT=0;
	for(int i=l;i<l+sz;i++)
		CNT+=a[i];
	return CNT;
} 
int main(){
	cin>>T;
	while(T--){
		cin>>n>>q>>s>>t;
		int m=q;
		while(q--){
			scanf("%d%d",l+q,r+q);
			l[q]--;r[q]--;
		}
		for(int i=n;i<int((n+sz-1)/sz)*sz;i++)s+='0',t+='0';
//		cout<<s<<endl<<t<<endl;
		n=int((n+sz-1)/sz)*sz;
		for(int i=0;i<n;i++)a[i]=t[i]-'0';
//		for(int i=0;i<n;i++)cout<<a[i]<<' ';cout<<endl;
		for(int i=0;i<n/sz;i++)dat[i]=-1,cnt[i]=-1;
		bool flag=1;
		for(int i=0;i<m;i++){
			int cnt0=0,cnt1=0;
			if(l[i]/sz==r[i]/sz){
				if(dat[l[i]/sz]!=-1)
					cnt1=dat[l[i]/sz]*(r[i]-l[i]+1);
				else
					for(int j=l[i];j<=r[i];j++)
						cnt1+=a[j];
			}else{
				int j=l[i],k=r[i];
				while(j%sz){
					if(dat[j/sz]!=-1)cnt1+=dat[j/sz];
					else cnt1+=a[j];j++;
				}
				while(k%sz!=sz-1){
					if(dat[k/sz]!=-1)cnt1+=dat[k/sz];
					else cnt1+=a[k];k--;
				}
				for(;j<k+(sz==1);j+=sz)
					if(dat[j/sz]==-1)
						if(cnt[j/sz]==-1){
//							cout<<j<<' '<<calc(j)<<endl;
							cnt[j/sz]=calc(j);
							cnt1+=cnt[j/sz];
						}
						else
							cnt1+=cnt[j/sz];
					else
						cnt1+=dat[j/sz]*sz; 
			}cnt0=r[i]-l[i]-cnt1+1;
			if(cnt0==cnt1)flag=0;
			if(l[i]/sz==r[i]/sz){
				dat[l[i]/sz]=-1;
				for(int j=l[i];j<=r[i];j++)
					if(cnt0>cnt1)
						a[j]=0;
					else
						a[j]=1;
			}else{
				int j=l[i],k=r[i];
				if(dat[l[i]/sz]!=-1)
					for(int j=int(l[i]/sz)*sz;j<int(l[i]/sz+1)*sz;j++)
						a[j]=dat[l[i]/sz];
				if(dat[r[i]/sz]!=-1)
					for(int j=int(r[i]/sz)*sz;j<int(r[i]/sz+1)*sz;j++)
						a[j]=dat[r[i]/sz];
				dat[l[i]/sz]=-1;dat[r[i]/sz]=-1;
				cnt[l[i]/sz]=-1;cnt[r[i]/sz]=-1;
				while(j%sz){
					if(cnt0>cnt1)a[j]=0;else a[j]=1;
					j++;
				}
				while(k%sz!=sz-1){
					if(cnt0>cnt1)a[k]=0;else a[k]=1;
					k--;
				}
				for(;j<k+(sz==1);j+=sz)
					if(cnt0>cnt1)
						dat[j/sz]=0;
					else
						dat[j/sz]=1;
			}/*cout<<cnt0<<' '<<cnt1<<endl;
			cout<<flag<<':';
			for(int j=0;j<n;j++)
				if(dat[j/sz]!=-1)
					cout<<dat[j/sz];
				else
					cout<<a[j];cout<<endl; */
		}
		for(int i=0;i<n;i++)
			if(dat[i/sz]!=-1)
				a[i]=dat[i/sz];
		for(int i=0;i<n;i++)
			if(a[i]!=s[i]-'0')
				flag=0;
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}