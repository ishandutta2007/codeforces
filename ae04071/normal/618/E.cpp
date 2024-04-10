#include <bits/stdc++.h>
using namespace std;
using pdd = pair<double,double>;

const double PI=acos(-1);
struct Matrix{
    double a[3][3];
    Matrix(int f=1) {
        for(int i=0;i<3;i++)for(int j=0;j<3;j++) a[i][j]=0.0;
        if(f==1) for(int i=0;i<3;i++) a[i][i]=1.0;
    }
    void setT(double vx,double vy) {
        for(int i=0;i<3;i++)for(int j=0;j<3;j++) a[i][j]=0;
        a[0][0]=a[1][1]=a[2][2]=1.0;
        a[0][2]=vx;
        a[1][2]=vy;
    }
    void setR(double angle) {
        for(int i=0;i<3;i++)for(int j=0;j<3;j++) a[i][j]=0;
        a[0][0] = a[1][1] = cos(angle);
        a[0][1] = sin(angle); a[1][0]=-sin(angle);
        a[2][2] = 1;
    }
    Matrix operator*(const Matrix &rhs)const {
        Matrix ret(0);
        for(int i=0;i<3;i++)for(int j=0;j<3;j++) for(int k=0;k<3;k++) {
            ret.a[i][j] += a[i][k] * rhs.a[k][j];
        }
        return ret;
    }
    pdd calPos(pdd pos) {
        /*
        printf("(%lf %lf)\n",pos.first,pos.second);
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) printf("%lf ",a[i][j]);
            puts("");
        }
        puts("@@@@@@@@@@@@@@@@");
        */
        return pdd(a[0][0]*pos.first + a[0][1]*pos.second + a[0][2],
                a[1][0]*pos.first + a[1][1]*pos.second + a[1][2]);
    }
};
struct seg_tr{
    const static int MAX=1<<19;
    Matrix tr[MAX<<1];
    void push(int cur) {
        if(cur<MAX) {
            int nx=cur<<1;
            tr[nx] = tr[cur] * tr[nx];
            tr[nx+1] = tr[cur] * tr[nx+1];
            tr[cur] = Matrix();
        }
    }
    void upd(int cur,int s,int f,int l,int r,Matrix &val) {
        push(cur);
        if(f<l || s>r) return;
        else if(l<=s && f<=r) tr[cur] = val*tr[cur];
        else {
            int nx=cur<<1,md=(s+f)>>1;
            upd(nx,s,md,l,r,val);
            upd(nx+1,md+1,f,l,r,val);
        }
    }
    void upd(int l,int r,Matrix &val) {
        upd(1,0,MAX-1,l,r,val);
    }
    void push_idx(int cur,int s,int f,int idx) {
        push(cur);
        if(s==f) ;
        else {
            int nx=cur<<1,md=(s+f)>>1;
            if(idx<=md) push_idx(nx,s,md,idx);
            else push_idx(nx+1,md+1,f,idx);
        }
    }
    void push_idx(int idx) {
        push_idx(1,0,MAX-1,idx);
    }
    void pushALL() {
        for(int i=1;i<MAX;i++) push(i);
    }
}st;

int n,m;
pdd arr[300001];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++) arr[i].first=i;
    while(m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1) {
            st.push_idx(b-1); st.push_idx(b);
            
            pdd vx = st.tr[seg_tr::MAX + b-1].calPos(arr[b-1]),
                vy = st.tr[seg_tr::MAX + b].calPos(arr[b]);
            pdd v(vy.first-vx.first, vy.second-vx.second);
            double r=sqrt(v.first*v.first + v.second*v.second);
            v.first *= c/r; v.second *= c/r;
            
            Matrix ret;
            ret.setT(v.first,v.second);
            st.upd(b,n,ret);
        } else {
            st.push_idx(b-1);
            pdd o = st.tr[seg_tr::MAX+b-1].calPos(arr[b-1]);
            
            Matrix pa,pb,pc;
            pa.setT(-o.first, -o.second);
            pb.setR(c*PI/180.0);
            pc.setT(o.first,o.second);

            Matrix ret = pc * (pb * pa);
            st.upd(b,n,ret);
        }

        st.push_idx(n);
        pdd ret = st.tr[seg_tr::MAX+n].calPos(arr[n]);
        printf("%.6lf %.6lf\n",ret.first,ret.second);
    }
    
    return 0;
}