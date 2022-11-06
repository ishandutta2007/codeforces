#include<bits/stdc++.h>
using namespace std;
int N;
char a[202][202];
char b[202][202];
char tmp[202][202];
void rot()
{
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            tmp[N-1-j][i] = a[i][j];
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            a[i][j] = tmp[i][j];
    
}
void flip()
{
    for(int i=0; i<N/2; ++i)
        for(int j=0; j<N; ++j)
            swap(a[i][j], a[N-1-i][j]);
}
bool same()
{
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            if(a[i][j] != b[i][j]) return false;
    return true;
}
void Yes()
{
    puts("Yes");
    exit(0);
}
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; ++i) scanf("%s", a[i]);
    for(int i=0; i<N; ++i) scanf("%s", b[i]);
    for(int i=0; i<4; ++i)
    {
        rot();
        if(same()) Yes();
    }
    flip();
    for(int i=0; i<4; ++i)
    {
        rot();
        if(same()) Yes();
    }
    puts("No");
    return 0;
}