#include <ctime>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

int N , K , sum[4005][4005] ;
struct Data{
    int val , ed , cnt ;
    Data( int _ = 0 , int __ = 0 , int ___ = 0 ) : val(_) , ed(__) , cnt(___) {} ;
} que[4005] , dp[4005] ;

struct io
{
    #define fs 48000000
    char ch[fs];int nr;
    io(){ch[fread(ch,1,fs,stdin)]=0;}
    inline int read()
    {
        int x=0;
        for(;ch[nr]<48;++nr);
        for(;ch[nr]>47;++nr)
            x=(x<<1)+(x<<3)+ch[nr]-48;
        return x;
    }
    inline void skip()
    {
        for(++nr;ch[nr]>10;++nr);
        ++nr;
    }
}io ;

int fr , ba ;
int val( Data x , int now ){
    return x.val + sum[now][now] - sum[x.ed][now] ;
}

int cnt ;
int better( Data x , Data y ){
    int lf = x.ed , rg = N , rt = N + 1 , mid ;
    while( lf <= rg ){
        mid = ( lf + rg ) >> 1 ;
        int t1 = val( x , mid ) , t2 = val( y , mid ) ;
        if( t1 < t2 || ( t1 == t2 && x.cnt < y.cnt ) )
            rt = mid , rg = mid - 1 ;
        else lf = mid + 1 ;
    } return rt ;
}

inline void Push( Data x ){
    while( ba > fr ){
        int t1 = better( que[ba] , que[ba-1] ) , t2 = better( x , que[ba] ) ;
        if( t1 > t2 || ( t1 == t2 && x.cnt <= que[ba].cnt ) ) ba -- ;
        else break ;
    } que[++ba] = x ;
}

Data calc( int cost ){
    fr = 1 , ba = 0 , Push( Data( 0 , 0 , 0 ) ) ;
    for( int i = 1 ; i <= N ; i ++ ){
        while( ba > fr ){
            int t1 = val( que[fr] , i ) , t2 = val( que[fr+1] , i ) ;
            if(t1==t2 && que[fr].cnt>que[fr+1].cnt) puts("gg");
            if( t1 > t2 || ( t1 == t2 && que[fr].cnt > que[fr+1].cnt ) ) fr ++ ;
            else break ;
        } dp[i] = Data( val( que[fr] , i ) + cost , i , que[fr].cnt + 1 ) ;
      //  que[++ba]=dp[i];
        Push( dp[i] ) ;
    } return dp[N] ;
}

void solve(){
    int lf = 0 , rg = 2000 * 2000 * 10 , ans ;
    while( lf <= rg ){
        int mid = ( lf + rg ) >> 1 ;
        Data res = calc( mid ) ;
        if( res.cnt == K )
            return ( void )printf( "%d\n" , res.val - K * mid ) ;
        if( res.cnt > K ) lf = mid + 1 ;
        else ans = mid , rg = mid - 1 ;
    } Data res = calc( ans ) ;
    printf( "%d\n" , res.val - K * ans ) ;
}

void read_( int &x ){
    register char ch = getchar() ;
    while( ch < '0' || ch > '9' ) ch = getchar() ;
    while( ch >='0' && ch <='9' ) x = ( x << 1 ) + ( x << 3 ) + ch - 48 , ch = getchar() ;
}

int main(){
    N = io.read() ; K = io.read() ;
    for( int i = 1 ; i <= N ; i ++ ){
        int *t1 = sum[i] , *t2 = sum[i-1] ;
        for( int j = 1 ; j <= N ; j ++ ){
            t1[j] = io.read() ;
            if( j <= i ) t1[j] = t2[j] + t1[j-1] - t2[j-1] ;
            else t1[j] += t2[j] + t1[j-1] - t2[j-1] ;
        }
    } solve() ;
}