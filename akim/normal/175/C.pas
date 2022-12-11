var a:array[1..1000,1..2]of int64;
    x:array[0..1000]of int64;
    s,t:int64;
    i,f,n:longint;
procedure qsort(l,r:longint);
var x,i,f,z:longint;
begin
 i:=l;f:=r;x:=a[random(r-l)+l,2];
 while i<=f do
 begin
  while a[i,2]<x do inc(i);
  while a[f,2]>x do dec(f);
  if i<=f then begin
                z:=a[i,2];
                a[i,2]:=a[f,2];
                a[f,2]:=z;
                z:=a[i,1];
                a[i,1]:=a[f,1];
                a[f,1]:=z;
                inc(i);
                dec(f);
               end;
 end;
 if l<f then qsort(l,f);
 if i<r then qsort(i,r);
end;
begin
 randomize;
 readln(n);
 for i:=1 to n do
  readln(a[i,1],a[i,2]);
 readln(x[0]);inc(x[0]);
 x[1]:=0;
 for i:=2 to x[0] do
  read(x[i]);
 x[x[0]+1]:=99999999999999;
 qsort(1,n);
 f:=1;s:=0;t:=0;
 for i:=1 to n do
 begin
  t:=t+a[i,1];
  s:=s+f*a[i,1]*a[i,2];
  while t>x[f+1] do 
  begin
   inc(f);
   s:=s+(t-x[f])*a[i,2];
  end;
 end;
 writeln(s);
end.
 end;