#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 1000005
int prec_lit[MAXN];
int prec_cif[MAXN];
int prec_[MAXN];
int prec_a[MAXN];
int prec_punct[MAXN];
char sir[MAXN];

inline bool lit(char x)
{
    return (x>='a' && x<='z');
}

inline bool cif(char x)
{
    return (x>='0' && x<='9');
}

int dr_nonlit[MAXN];
int dr_punct[MAXN];
int st_inval[MAXN];

inline int sum_lit(int a,int b)
{
    return (prec_lit[b]-prec_lit[a-1]);
}

inline int sum_cif(int a,int b)
{
    return (prec_cif[b]-prec_cif[a-1]);
}

int main()
{
    cin.get(sir+1,MAXN);
    int n=strlen(sir+1),i;

    for(i=1;i<=n;i++)
    {
        prec_lit[i]=prec_lit[i-1];
        prec_cif[i]=prec_cif[i-1];
        prec_[i]=prec_[i-1];
        prec_a[i]=prec_a[i-1];
        prec_punct[i]=prec_punct[i-1];

        if(lit(sir[i]))
            prec_lit[i]++;
        else if(cif(sir[i]))
            prec_cif[i]++;
        else if(sir[i]=='_')
            prec_[i]++;
        else if(sir[i]=='@')
            prec_a[i]++;
        else
            prec_punct[i]++;
    }

    int poz=n+1;
    for(i=n;i>=1;i--)
    {
        if(sir[i]=='.')
            dr_nonlit[i]=poz;
        if(!lit(sir[i]))
            poz=i;
    }

    poz=n+1;
    for(i=n;i>=1;i--)
    {
        if(sir[i]=='@')
            dr_punct[i]=poz;
        else if(sir[i]=='.')
            poz=i;
    }

    poz=0;
    for(i=1;i<=n;i++)
    {
        if(sir[i]=='@')
            st_inval[i]=poz;
        if(sir[i]=='@' || sir[i]=='.')
            poz=i;
    }

    long long int cate=0;
    for(i=2;i<n;i++)
        if(sir[i]=='@')
        {
            //De vazut si alte cazuri particulare
            if(st_inval[i]==(i-1))
                continue;
            if((dr_punct[i]==(i+1)) || (dr_punct[i]>=n))
                continue;
            if((sum_lit(i+1,dr_punct[i]-1)+sum_cif(i+1,dr_punct[i]-1))!=(dr_punct[i]-i-1))
                continue;
            if(dr_nonlit[dr_punct[i]]==(dr_punct[i]+1))
                continue;

            cate+=(1ll*sum_lit(st_inval[i],i-1)*(dr_nonlit[dr_punct[i]]-dr_punct[i]-1));
        }
    cout<<cate<<'\n';

    return 0;
}