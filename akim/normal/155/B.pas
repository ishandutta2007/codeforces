var a:array[1..1100,1..2]of longint;
    z,n,i,f,s,h:longint;
begin
 readln(n);
 for i:=1 to n do
  readln(a[i,1],a[i,2]);
 for i:=1 to n-1 do
  for f:=i+1 to n do
   if a[i,2]<a[f,2] then begin
                          z:=a[i,2];
                          a[i,2]:=a[f,2];
                          a[f,2]:=z;
                          z:=a[i,1];
                          a[i,1]:=a[f,1];
                          a[f,1]:=z;
                         end else
   if a[i,2]=a[f,2] then
    if a[i,1]<a[f,1] then begin
                           z:=a[i,1];
                           a[i,1]:=a[f,1];
                           a[f,1]:=z;
                          end;
 h:=1;i:=0;s:=0;
 while (h>i)and(i<=n) do
 begin
  inc(i);
  inc(s,a[i,1]);
  inc(h,a[i,2]);
 end;
 writeln(s);
end.