int main()
{


    int n;
    scanf("%d", &n);
    
    int a[n];
    for (int i = 0; i<n; i++) scanf("%d", &a[i]);
    int temp = 0;
    int idx = 0;
    int kek = 1;
    while ((idx<n-1)&&(a[idx]==a[idx+1])) 
    {
        idx++;
        temp++;
    }
    idx++;
    while (idx<n)
    {
        int temp1 = 0;
        while ((idx<n-1)&&(a[idx]==a[idx+1]))
        {
            idx++;
            temp1++;
        }
        idx++;
        if (temp1!=temp) kek = 0;
    }
    if (kek==1) printf("YES");
    else printf("NO");

}