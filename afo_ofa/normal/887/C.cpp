#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
typedef long long LL;
int a[7][5],b[7][5];
inline bool sf() {
    for(int i=1;i<=6;i++)
        for(int j=2;j<=4;j++)
            if(b[i][j]!=b[i][j-1])
                return false;
    return true;
}
inline void fz(){
    for(int i=1;i<=6;i++)
        for(int j=1;j<=4;j++)
            b[i][j]=a[i][j];
}
int main() {
    for(int j=1;j<=4;j++)
        scanf("%d",&a[1][j]);
    for(int j=1;j<=4;j++)
    	scanf("%d",&a[2][j]);
    for(int j=1;j<=4;j++)
    	scanf("%d",&a[3][j]);
    scanf("%d%d%d%d",&a[5][2],&a[5][4],&a[5][1],&a[5][3]);
    scanf("%d%d%d%d",&a[6][3],&a[6][1],&a[6][4],&a[6][2]);
    scanf("%d%d%d%d",&a[4][4],&a[4][3],&a[4][2],&a[4][1]);
  //  for(int i=1;i<=6;i++,puts(""))
  //  	for(int j=1;j<=4;j++)
//   		cout<<a[i][j]<<" ";
    fz();
//    if(sf()){
//        puts("YES");
//        return 0;
//    }
    int x = b[1][1],y = b[1][2];
    b[1][1] = b[6][1],b[1][2] = b[6][2];
    b[6][1] = b[3][4],b[6][2] = b[3][3];
    b[3][4] = b[5][1],b[3][3] = b[5][2];
    b[5][1] = x,b[5][2] = y;
    if(sf()){
        puts("YES");
        return 0;
    }
    fz();
    x = b[1][1],y = b[1][2];
    b[1][1] = b[5][1],b[1][2] = b[5][2];
    b[5][1] = b[3][4],b[5][2] = b[3][3];
    b[3][4] = b[6][1],b[3][3] = b[6][2];
    b[6][1] = x,b[6][2] = y;
    if(sf()){
        puts("YES");
        return 0;
    }
    fz();
    x = b[1][2],y = b[1][4];
    b[1][2] = b[4][2],b[1][4] = b[4][4];
    b[4][2] = b[3][2],b[4][4] = b[3][4];
    b[3][2] = b[2][2],b[3][4] = b[2][4];
    b[2][2] = x,b[2][4] = y;
    if(sf()){
        puts("YES");
        return 0;
    }
    fz();
    x = b[1][2],y = b[1][4];
    b[1][2] = b[2][2],b[1][4] = b[2][4];
    b[2][2] = b[3][2],b[2][4] = b[3][4];
    b[3][2] = b[4][2],b[3][4] = b[4][4];
    b[4][2] = x,b[4][4] = y;
    if(sf()){
        puts("YES");
        return 0;
    }
    fz();
    x = b[5][2],y = b[5][4];
    b[5][2] = b[2][1],b[5][4] = b[2][2];
    b[2][1] = b[6][3],b[2][2] = b[6][1];
    b[6][3] = b[4][4],b[6][1] = b[4][3];
    b[4][4] = x,b[4][3] = y;
    if(sf()){
        puts("YES");
        return 0;
    }
    fz();
    x = b[5][2],y = b[5][4];
    b[5][2] = b[4][4],b[5][4] = b[4][3];
    b[4][4] = b[6][3],b[4][3] = b[6][1];
    b[6][3] = b[2][1],b[6][1] = b[2][2];
    b[2][1] = x,b[2][2] = y;
    if(sf()){
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}