#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
    while(1)
    {
        int n,w,N;
        cin>>n>>w;
        N=2*n;
        int cupSize[N];
        for(int i=0; i<2*n; i++)
            cin>>cupSize[i];
        sort(cupSize,cupSize+N);
//    for(int i=0;i<2*n;i++)
//        cout<<cupSize[i]<<" ";

        int boys[n],girls[n];

        for(int i=0,j=0; i<N; i++)
        {
            if(i<n)
                girls[i]=cupSize[i];
            else
                boys[j++]=cupSize[i];
        }
//        cout<<endl<<endl;
//        for(int i=0; i<n; i++)
//            cout<<boys[i]<<" ";
//
//        cout<<endl<<endl;
//        for(int i=0; i<n; i++)
//            cout<<girls[i]<<" ";
//        cout<<endl<<endl;

        // deal with b[0] and check g[0]==b[0]/2 ?
        // along with check if w is exceeded or not


        double ans,btem=boys[0],gtem=girls[0],flag=0;
        while(1)
        {
            //cout<<"|";
            if(w>=btem/2*(3*n) )  //2n+n==3n
            {
                if(btem/2<=gtem)
                {
                    ans=btem/2;
                    break;
                }
                else
                {
                    btem=2*(gtem);
                }

            }
            else
            {
                btem=(double)w*2.00/(3.00*(double)n);
            }

        }
printf("%.12lf\n",ans*(3.00*(double)n));
        return 0;


    }




}