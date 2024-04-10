#include <bits/stdc++.h>
using namespace std;
typedef struct pii{
    int x, y;
}pii;
int T;
char A[200100];
pii B[200100];
int main()
{
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> A;
        int len=strlen(A);
        int smax=0, smay=0, bigx=0, bigy=0;
        long long chax, chay;
        for(int j=1;j<=len;j++)
        {
            if(A[j-1]=='W')
            {
                B[j].y=B[j-1].y+1;
                B[j].x=B[j-1].x;
                bigy=max(bigy, B[j].y);
            }
            else if(A[j-1]=='A')
            {
                B[j].x=B[j-1].x-1;
                B[j].y=B[j-1].y;
                smax=min(smax, B[j].x);
            }
            else if(A[j-1]=='S')
            {
                B[j].y=B[j-1].y-1;
                B[j].x=B[j-1].x;
                smay=min(smay, B[j].y);
            }
            else
            {
                B[j].x=B[j-1].x+1;
                B[j].y=B[j-1].y;
                bigx=max(bigx, B[j].x);
            }
        }
        int bix=0, jox=0, joxp=1, biy=0, joy=0, joyp=1;
        for(int j=0;j<=len;j++)
        {
            if(bigy>=smay+2)
            {
                if(B[j].y==bigy)
                {
                    if(biy==0)
                        joy=1, biy=1;
                    else if(biy==1 && joy==-1)
                        biy=2, joy=1;
                    else if(biy==2 && joy==-1)
                        joyp=-1;
                }
                if(B[j].y==smay)
                {
                    if(biy==0)
                        joy=-1, biy=1;
                    else if(biy==1 && joy==1)
                        biy=2, joy=-1;
                    else if(biy==2 && joy==1)
                        joyp=-1;
                }
            }
            else
                joyp=-1;
            if(bigx>=smax+2)
            {
                if(B[j].x==bigx)
                {
                    if(bix==0)
                        jox=1, bix=1;
                    else if(bix==1 && jox==-1)
                        bix=2, jox=1;
                    else if(bix==2 && jox==-1)
                        joxp=-1;
                }
                if(B[j].x==smax)
                {
                    if(bix==0)
                        jox=-1, bix=1;
                    else if(bix==1 && jox==1)
                        bix=2, jox=-1;
                    else if(bix==2 &&jox==1)
                        joxp=-1;
                }
            }
            else
                joxp=-1;
        }
        chax=bigx-smax+1;
        chay=bigy-smay+1;
        if(joxp==1 &&joyp==1)
        {
            cout << min((chax-1)*chay, (chay-1)*chax) << '\n';
        }
        else if(joyp==1)
            cout << chax*(chay-1) <<'\n';
        else if(joxp==1)
            cout << (chax-1)*chay << '\n';
        else
            cout << chax*chay << '\n';
    }
}