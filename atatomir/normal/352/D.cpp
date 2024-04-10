#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define zeros(x) (((x)^(x-1))&(x))

using namespace std;

struct Elem{
    long v,pos;
    Elem operator()(long lval,long lpos){
        v = lval; pos=lpos;
        return *this;
    }
} vElem;

long invs,v;
long n,i,aib[3005];
vector<Elem> a;
long ans[3][3],aux[3][3];

bool cmp(const Elem& a,const Elem& b){
    return (a.v < b.v);
}
void add(long x){
    while(x <= n) {
        aib[x]++;
        x += zeros(x);
    }
}
long sum(long x){
    long ans=0;
    while(x > 0){
        ans += aib[x];
        x -= zeros(x);
    }
    return ans;
}
long getInvsCount() {
    scanf("%ld\n",&n);
    for(i=1;i<=n;i++) {
        scanf("%ld",&v);
        a.push_back(vElem(v,i));
    }
    sort(a.begin(),a.end(),cmp);

    long ans=0;
    for(i=0;i<n;i++){
        ans += sum(a[i].pos);
        add(a[i].pos);
    }

    return ((n-1)*n)/2 - ans;
}

void multiplicate(long a[3][3],long b[3][3]){
    long i,j,dim;
    long answer[3][3];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++) answer[i][j] = 0;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            answer[i][j] = 0;
            for(dim=0;dim<3;dim++) answer[i][j] += a[i][dim]*b[dim][j];
        }
    }
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            a[i][j] = answer[i][j];
}

int main()
{
    invs = getInvsCount();

    ans[0][0] = ans[1][1] = ans[2][2] = 1;
    aux[0][1] = aux[1][0] = aux[2][2] = 1; aux[2][1] = 4;

    if(invs == 0){
        printf("0");
        return 0;
    }

    invs--;
    while(invs){
        if(invs&1) multiplicate(ans,aux);
        multiplicate(aux,aux);
        invs >>= 1;
    }

    printf("%ld",ans[1][1]+ans[2][1]);

    return 0;
}