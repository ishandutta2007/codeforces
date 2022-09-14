var n,m,x,y,i:longint;
    a:array[1..100] of longint;
begin
read (n);
for i:=1 to n do read (a[i]);
read (m);
for i:=1 to m do 
    begin
     read (x,y);
     if x>1 then 
         a[x-1]:=a[x-1]+y-1;
     if x<n then 
         a[x+1]:=a[x+1]+a[x]-y;
     a[x]:=0;
    end;
for i:=1 to n do
    writeln (a[i]);   
end.