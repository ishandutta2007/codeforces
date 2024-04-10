main()
    {int x,y,s;
    scanf("%d%d",&x,&y);
    s=(x>0?x:-x)+(y>0?y:-y);
    printf("%d %d %d %d",x<0?-s:0,x<0?0:y>0?s:-s,x<0?0:s,x<0?y>0?s:-s:0);
    return 0;}