#include <iostream>
#include <algorithm>

using namespace std;

int zile[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
                 {31,29,31,30,31,30,31,31,30,31,30,31}};

inline bool leap(int x)
{
    /*if(x%400==0)
        return 1;
    if(x%100==0)
        return 0;
    if(x%4==0)
        return 1;
    return 0;*/

    if(x%4==0){
        if(x%100==0){
            if(x%400==0)
                return 1;
            return 0;
        }
        return 1;
    }
    return 0;
}

inline bool day(int y,int m,int d)
{
    return (d<=zile[leap(y)][m-1]);
}

inline bool mic(int y1,int m1,int d1,int y2,int m2,int d2)
{
    if(y1<y2)
        return 1;
    if(y1>y2)
        return 0;

    if(m1<m2)
        return 1;
    if(m1>m2)
        return 0;

    if(d1<=d2)
        return 1;
    return 0;
}

int main()
{
    int y1,m1,d1,y2,m2,d2;
    char x;

    cin>>y1>>x>>m1>>x>>d1;
    cin>>y2>>x>>m2>>x>>d2;

    if(!mic(y1,m1,d1,y2,m2,d2)){
        swap(y1,y2);
        swap(m1,m2);
        swap(d1,d2);
    }

    int amount=0;
    for(int i=1900;i<=2038;i++)
        for(int j=1;j<=12;j++)
            for(int k=1;k<=31;k++)
                if(day(i,j,k))
                    if(mic(y1,m1,d1,i,j,k) && mic(i,j,k,y2,m2,d2))
                        amount++;

    cout<<amount-1<<'\n';
    return 0;
}