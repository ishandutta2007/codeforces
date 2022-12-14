#include <bits/stdc++.h>
using namespace std;
int N;
char A[101010];
int B[10];
int main()
{
    cin >> N;
    cin >> A;
    for(int i=0;i<N;i++)
    {
        if(A[i]<='9' && A[i]>='0')
            B[A[i]-'0']=0;
        else
        {
            if(A[i]=='L')
            {
                int tmp=0;
                while(B[tmp]!=0)
                    tmp++;
                B[tmp]=1;
            }
            else
            {
                int tmp=9;
                while(B[tmp]!=0)
                    tmp--;
                B[tmp]=1;
            }
        }
    }
    for(int i=0;i<=9;i++)
        cout << B[i] ;
}