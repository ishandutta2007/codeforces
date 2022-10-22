#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
int n;
const int N=2e6;
int a[N],b[N];
int ans=0;
int gcd(int x,int y)
{
  if (y==0) return x; else return gcd(y,x%y);
}
void pu(int x,int y)
{
  if (x==1)
  {
    cout<<"> "<<y<<endl;
  } else
  {
    cout<<"? "<<y<<endl;
  }
  fflush(stdout);
}
int main()
{
  srand(19280817);
  cin>>n;
  rep(i,1,n) a[i]=i;
  random_shuffle(a+1,a+n+1);
    random_shuffle(a+1,a+n+1);
      random_shuffle(a+1,a+n+1);
        random_shuffle(a+1,a+n+1);
          random_shuffle(a+1,a+n+1);
            random_shuffle(a+1,a+n+1);
              random_shuffle(a+1,a+n+1);
                random_shuffle(a+1,a+n+1);
                  random_shuffle(a+1,a+n+1);
                    random_shuffle(a+1,a+n+1);
                      random_shuffle(a+1,a+n+1);
  int h=0,t=1e9;
  int cnt=0;
  while (h<t)
  {
    cnt++;
    int mid=(h+t)/2;
    pu(1,mid);
    int x;
    cin>>x;
    if (x==0) t=mid; else h=mid+1;
  }
  int len=min(60-cnt,n);
  rep(i,1,len)
  {
    pu(2,a[i]);
    cin>>b[i];
  }
  sort(b+1,b+len+1);
  if (n!=2)
  {
    rep(i,1,len-2)
      ans=gcd(ans,gcd(b[i+1]-b[i],b[i+2]-b[i+1]));
  } else
  {
    ans=b[2]-b[1];
  }
  cout<<"!"<<" "<<h-(n-1)*ans<<" "<<ans<<endl;
  fflush(stdout);
  fflush(stdout);
  return 0; 
}