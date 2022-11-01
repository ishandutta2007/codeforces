#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

int main()
{
    int n;
    char s[20],t1[20],t2[20],t3[20];
    cin >> n;
    for (int i=0; i<n; i++)
    {
        for (int i=0; i<20; i++)
        {
            s[i]=0;
            t1[i]=0;
            t2[i]=0;
            t3[i]=0;
        }
        cin>>s;
        bool boo = false;
        for (int j=1; j<strlen(s); j++)
        {
            if (s[j]=='C' && isdigit(s[j - 1]))
                boo = true;
        }
        if (boo)
        {
            strcpy(t2,strstr(s,"C") + 1);
            strstr(s,"C")[0] = 0;
            strcpy(t1,s + 1);
            int a,b,k=0;
            sscanf(t1,"%d",&a);
            sscanf(t2,"%d",&b);
            do
            {
                b-=1;
                t3[k]=(char)('A' + b%26);
                if (t3[k]<'A')
                    t3[k]+=26;
                k++;
                b/=26;
            }
            while (b>0);
            for (int j=strlen(t3)-1; j>=0; j--)
                cout<<t3[j];
            cout << a << endl;
        }
        else
        {
            int k;
            for (int j=0; j<strlen(s); j++)
            {
                if (isdigit(s[j]))
                {
                    k = j;
                    break;
                }
            }
            strcpy(t2,s + k);
            s[k] = 0;
            strcpy(t1,s);
            int a,b=0;
            sscanf(t2,"%d",&a);
            for (int j=0; j<strlen(t1); j++)
                b+=powl(26,strlen(t1)-j-1) * (t1[j] - 'A'+1);
            printf("R%dC%d\n",a,b);
        }
    }
    return 0;
}