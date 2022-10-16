#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char sir[1005];
    cin.get(sir,1005);
    long long int l=strlen(sir),i,nb=0,ns=0,nc=0;

    for(i=0;i<l;i++)
    {
        if(sir[i]=='B')
            nb++;
        else if(sir[i]=='S')
            ns++;
        else
            nc++;
    }

    long long int b,s,c,pb,ps,pc;
    cin>>b>>s>>c>>pb>>ps>>pc;
    if(nb==0)
        b=0;
    if(nc==0)
        c=0;
    if(ns==0)
        s=0;

    long long int ans=0;
    long long int r;
    cin>>r;

    bool stop=false;
    while(!stop)
    {
        stop=true;
        if(b>=nb && s>=ns && c>=nc)
        {
            ans++;
            b-=nb;
            c-=nc;
            s-=ns;
            if(b==0 && c==0 && s==0)
                break;
            stop=false;
        }
        else
        {
            if(b<nb)
            {
                if(r<((nb-b)*pb))
                    break;
                r-=((nb-b)*pb);
                b=nb;
                stop=false;
            }

            if(c<nc)
            {
                if(r<((nc-c)*pc))
                    break;
                r-=((nc-c)*pc);
                c=nc;
                stop=false;
            }

            if(s<ns)
            {
                if(r<((ns-s)*ps))
                    break;
                r-=((ns-s)*ps);
                s=ns;
                stop=false;
            }
        }
    }
    long long int pret=nb*pb+nc*pc+ns*ps;
    ans+=(r/pret);
    cout<<ans<<'\n';

    return 0;
}