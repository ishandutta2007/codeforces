var a,b,c,d,suab,sucd:array[0..1000]of longint;
    cur1,cur2,min,t,i,j,n,x,y,er,suma,sumb,cur,ans:longint;
begin
 read(n);
 suma:=0;
 sumb:=0;
 cur1:=1;
 cur2:=1;
 suab[0]:=0;
 sucd[0]:=0;
 for i:=1 to n do
   begin
     read(x,y);
     inc(min,x);
     inc(suma,x);
     if x=1 then
       begin
         a[cur1]:=x;
         b[cur1]:=y;
         inc(cur1);
       end;
     if x=2 then
       begin
         c[cur2]:=x;
         d[cur2]:=y;
         inc(cur2);
       end;
   end;

 for i:=1 to cur1-2 do
   for j:=1 to cur1-1-i do
     if (b[j])>(b[j+1]) then
       begin
         t:=a[j];
         a[j]:=a[j+1];
         a[j+1]:=t;
         t:=b[j];
         b[j]:=b[j+1];
         b[j+1]:=t;
       end;
       
 for i:=1 to cur2-2 do
   for j:=1 to cur2-1-i do
     if (d[j])>(d[j+1]) then
       begin
         t:=c[j];
         c[j]:=c[j+1];
         c[j+1]:=t;
         t:=d[j];
         d[j]:=d[j+1];
         d[j+1]:=t;
       end;
       
 suab[1]:=b[1];
 for i:=2 to cur1-1 do
   suab[i]:=suab[i-1]+b[i];
 sucd[1]:=d[1];
 for i:=2 to cur2-1 do
   sucd[i]:=sucd[i-1]+d[i];


 for i:=0 to cur1-1 do
   for j:=0 to cur2-1 do
     begin
       if cur2-1-j>=0 then
         suma:=cur1-i-1+2*(cur2 -1-j)
       else
         suma:=cur1-i-1;
       sumb:=suab[i]+sucd[j];

       if suma>=sumb then
         if suma<min then
           min:=suma;
     end;
 write(min);
end.