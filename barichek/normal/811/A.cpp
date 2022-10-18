#include <bits/stdc++.h>

using namespace std;

bool reb[100][100];
int n;

main()
{int a,b;
cin>>a>>b;
for (int i=1;i<=100000;i++)
{if (i%2==1) a=a-i;
else b=b-i;
if (a<0) {cout<<"Vladik\n";
break;


}
else if (b<0) {
    cout<<"Valera\n";
    break;
}
}

}