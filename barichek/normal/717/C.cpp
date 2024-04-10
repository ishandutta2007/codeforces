#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
#define endl '\n'
#define all(v) (v).begin(),(v).end()
#define f first
#define s second
#define mp make_pair
//#define double long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 using namespace std;

 char r_ch,r_minus;
 int w_m[100],w_kol,w_i;

 void read_int(int &x)
 {
    x = 0;
    r_ch = getchar();
    if(r_ch=='-') r_minus = r_ch; else x = r_ch - '0',r_minus = 0;
     while(1)
     {
        r_ch=getchar();
        if(!(r_ch>='0' && r_ch<='9'))
           {
               if(r_minus) x = -x;
                return;
           }
        x*=10;
        x+=r_ch - '0';
     }
     if(r_minus) x= -x;
 }

 void read_long_long(long long &x)
 {
    x = 0;
    r_ch = getchar();
    if(r_ch=='-') r_minus = r_ch; else x = r_ch - '0',r_minus = 0;
     while(1)
     {
        r_ch=getchar();
        if(!(r_ch>='0' && r_ch<='9'))
           {
               if(r_minus) x = -x;
                return;
           }
        x*=10;
        x+=r_ch - '0';
     }
     if(r_minus) x= -x;
 }

 void write_int(int x)
 {
    if(x<0) putchar('-'),x=-x;
     w_kol = 0;
     while(1)
     {
         w_m[++w_kol] = x % 10;
         x/=10;
         if(!x) break;
     }
     for(w_i=w_kol;w_i>0;--w_i)
        putchar(char('0' + w_m[w_i]));
 }

  void write_long_long(long long x)
 {
    if(x<0) putchar('-'),x=-x;
     w_kol = 0;
     while(1)
     {
         w_m[++w_kol] = x % 10;
         x/=10;
         if(!x) break;
     }
     for(w_i=w_kol;w_i>0;--w_i)
        putchar(char('0' + w_m[w_i]));
 }

 const int N = 2e5 + 121,md = 10007;
 int a[N],b[N],i,n,ans,j;

 void add(int &a,int b)
 {
     a+=b;
     a%=md;
 }

  //int
   main()
  {

      fast;

        cin>>n;
         for(i=1;i<=n;++i) cin>>a[i],b[i] = a[i];

         sort(a+1,a+n+1);
         sort(b+1,b+n+1);
         j = n;
          for(i=1;i<=n;++i)
             add(ans,a[i] * b[j--] % md);

          cout<<ans<<endl;

  }