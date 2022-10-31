#include<cstdio>
#include<cmath>
#include<complex>
#include<vector>
#include<algorithm>
#define PI 3.14159265359
#define N 200100
#define M 200100
using namespace std;
void FFT(vector<complex<double> >& f,int m,int sign){
    complex<double> t,a,b,w,x;
    int i,j,k;
    for(i=1,j=0;i<m;i++){
        for(k=m>>1;!((j^=k)&k);k>>=1);
        if(i<j) swap(f[i],f[j]);
    }
    int r;
    for(r=2;r<=m;r<<=1){
        w=complex<double>(cos(2*PI/r),sign*sin(2*PI/r));
        for(i=0;i<m;i+=r){
            x=1;
            for(j=i;j<i+r/2;j++){
                a=f[j]+x*f[j+r/2];
                b=f[j]-x*f[j+r/2];
                f[j]=a;
                f[j+r/2]=b;
                x*=w;
            }
        }
    }
}
vector<int> poly_mul(vector<int>& A,vector<int>& B){
    vector<complex<double> > FA,FB;
    vector<int> ret;
    int m=1,i;
    while(m<A.size()+B.size()-1) m<<=1;
    complex<double> w(cos(2*PI/m),sin(2*PI/m));
    ret.resize(A.size()+B.size()-1);
    FA.resize(m);
    FB.resize(m);
    for(i=0;i<A.size();i++) FA[i]=complex<double>(A[i]);
    for(i=0;i<B.size();i++) FB[i]=complex<double>(B[i]);
    FFT(FA,m,1);
    FFT(FB,m,1);
    for(i=0;i<m;i++) FA[i]*=FB[i];
    FFT(FA,m,-1);
    for(i=0;i<ret.size();i++){
        ret[i]=floor(FA[i].real()/m+0.5);
    }
    return ret;
}
char s[N],t[M];
int fit[M];
int main(){
    int n,m,k,i,j,l,r,now[4],cnt[4]={},ans=0;
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s%s",s,t);
    vector<int> ps[4],pa[4],pb[4],pc[4];
    for(i=0;i<4;i++){
        ps[i].resize(n);
        pa[i].resize(n);
        pb[i].resize(m);
    }
    for(i=0;i<n;i++){
        now[0]=(s[i]=='A');
        now[1]=(s[i]=='T');
        now[2]=(s[i]=='C');
        now[3]=(s[i]=='G');
        for(j=0;j<4;j++){
            ps[j][i]=(i?ps[j][i-1]:0)+now[j];
        }
    }
    for(i=0;i<n;i++){
        l=i-k<0?0:i-k;
        r=i+k>=n?n-1:i+k;
        for(j=0;j<4;j++){
            if(ps[j][r]>(l?ps[j][l-1]:0)) pa[j][i]=1;
            else pa[j][i]=0;
        }
    }
    for(i=0;i<m;i++){
        if(t[i]=='A') pb[0][m-1-i]=1,cnt[0]++;
        if(t[i]=='T') pb[1][m-1-i]=1,cnt[1]++;
        if(t[i]=='C') pb[2][m-1-i]=1,cnt[2]++;
        if(t[i]=='G') pb[3][m-1-i]=1,cnt[3]++;
    }
    for(i=0;i<4;i++){
        pc[i]=poly_mul(pa[i],pb[i]);
        for(j=0;j<n-m+1;j++){
            if(pc[i][j+m-1]==cnt[i]) fit[j]++;
        }
    }
    for(i=0;i<n-m+1;i++) ans+=(fit[i]==4);
    printf("%d\n",ans);
    return 0;
}