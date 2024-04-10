#include"bits/stdc++.h"
using namespace std;
map<int,int>m;
struct node
{
    int data;
    node *next;
};
class Stack
{
public:
    node *head,*rear;
    int len;
    int size(){return len;}
    void push(int a)
    {
        if(len)
        {
            rear=head;
            head=new node;
            head->next=rear;
        }
        else
        {
            head=new node;
            head->next=NULL;
        }
        head->data=a;
        len++;
    }
    int pop()
    {
        int n;
        len--;
        rear=head;
        n=rear->data;
        head=head->next;
        delete rear;
        return n;
    }
};
Stack save[100005];
void add(int k)
{
    if(m.find(k)==m.end())m[k]=1;
    else m[k]++;
}
int ans[100005][3],nn;
int add(int a,int b,int c)
{
    int d[3];d[0]=a;d[1]=b;d[2]=c;
    sort(d,d+3);
    ans[nn][0]=d[2];ans[nn][1]=d[1];ans[nn][2]=d[0];
    nn++;
}
int main()
{
    for(int i=0;i<100005;i++)
    {
        save[i].head=0;
        save[i].rear=0;
        save[i].len=0;
    }//save[0].push(4);save[0].push(3);cout<<save[0].pop()<<endl;cout<<save[0].pop()<<endl;
    int n;
    cin>>n;
    int t;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        add(t);
    }
    t=0;
    for(map<int,int>::iterator it=m.begin();it!=m.end();++it)
    {
        save[it->second].push(it->first);
    }
    //if(m.size()<3)
    {
        //cout<<0<<endl<<endl;
        //return 0;
    }
    int a=100000,b,c,sa,sb,sc;
    for(;a>0;a--)if(save[a].size())break;
    while(1)
    {
        for(;a>0;a--)if(save[a].size())break;
        if(a==0)break;
        sa=save[a].pop();
        for(b=a;b>0;b--)if(save[b].size())break;
        if(b==0)break;
        sb=save[b].pop();
        for(c=b;c>0;c--)if(save[c].size())break;
        if(c==0)break;
        sc=save[c].pop();
        //cout<<a<<b<<c<<endl;cout<<sa<<" "<<sb<<" "<<sc<<endl;;;;
        if(a>1)save[a-1].push(sa);
        if(b>1)save[b-1].push(sb);
        if(c>1)save[c-1].push(sc);
        a++;
        add(sa,sb,sc);
    }
    cout<<nn<<endl;
    for(int i=0;i<nn;i++)
    {
        printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    }
    return 0;
}