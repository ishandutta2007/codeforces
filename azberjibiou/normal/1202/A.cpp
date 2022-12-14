#include <bits/stdc++.h>
using namespace std;
int T, asma, bsma;
char Ap[101010], Bp[101010], A[101010], B[101010];
int main()
{
    cin >> T;
    for(int i=0;i<T;i++)
    {
        bsma=0;
        asma=0;
        cin >> Ap >> Bp;
        int len=strlen(Bp);
        for(int j=0;j<len;j++)
        {
            B[j]=Bp[len-1-j];
        }
        len=strlen(Ap);
        for(int j=0;j<len;j++)
        {
            A[j]=Ap[len-1-j];
        }
        len=strlen(Bp);
        for(int j=0;j<len;j++)
        {
            if(B[j]=='1')
            {
                bsma=j;
                break;
            }
        }
        for(int j=bsma;;j++)
        {
            if(A[j]=='1')
            {
                break;
            }
            asma++;
        }
        cout << asma << '\n';
    }
}