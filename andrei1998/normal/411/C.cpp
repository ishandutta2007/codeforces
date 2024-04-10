#include <iostream>

using namespace std;

int v[4][2];
int verd[2][2][2][2];

int main()
{
    int i,j,k,l;
    for(i=0;i<4;i++)
        cin>>v[i][0]>>v[i][1];

    int d0,a0,d1,a1;

    //bool all_2=true;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
        if((i+j)%2)
        {
            if(!i)
                d0=v[0][i];
            else
                d0=v[1][j];

            if(i)
                a0=v[0][i];
            else
                a0=v[1][j];
            //bool ok=true;
            for(k=0;k<2;k++)
                for(l=0;l<2;l++)
                if((k+l)%2)
                {
                    if(!k)
                        d1=v[2][k];
                    else
                        d1=v[3][l];

                    if(k)
                        a1=v[2][k];
                    else
                        a1=v[3][l];
                    if(a1>d0 && d1>a0)
                        verd[i][j][k][l]=2;
                    else if(a1<d0 && d1<a0)
                        verd[i][j][k][l]=0;
                    else
                        verd[i][j][k][l]=1;
         //           cout<<"verd["<<i<<' '<<j<<' '<<k<<' '<<l<<"]="<<verd[i][j][k][l]<<endl;
           //         cout<<d0<<' '<<a0<<' '<<d1<<' '<<a1<<endl;
                    //if(verd[i][j][k][l]!=0)
                    //    ok=false;
                    //if(verd[i][j][k][l]!=2)
                    //    all_2=false;
                }
                //if(ok)
                //{
                //    cout<<"Team 1\n";
                //    return 0;
                //}
        }

    //if(all_2)
    //{
    //    cout<<"Team 2\n";
    //}
    //else
    //   cout<<"Draw\n";

    int cate=0;
    bool gasit=0;

    for(i=0;i<2;i++)
    {
        j=1-i;

        bool ok=true;
        gasit=0;

        for(k=0;k<2;k++)
        {
            l=1-k;
            if(verd[i][j][k][l]!=0)
            {
                ok=false;
            }
            if(verd[i][j][k][l]==2)
            {
                if(!gasit)
                {
                    cate++;
                    gasit=1;
                }
            }
        }

        if(ok)
        {
            cout<<"Team 1\n";
            return 0;
        }
    }
    //cout<<"cate="<<cate<<endl;

    if(cate==2)
        cout<<"Team 2\n";
    else
        cout<<"Draw\n";
    return 0;
}