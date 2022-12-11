var a,y:array[1..200000]of longint;
    x:array[1..200000]of boolean;
    b:array[1..400000,1..2]of longint;
    n,k,l,i,z:longint;
procedure dfs(q:longint);
var i:longint;
begin
 x[q]:=true;
 i:=a[q];
 while i>0 do
 begin
  if not(x[b[i,1]]) then begin if i mod 2=1 then k:=k+1;dfs(b[i,1]);end;
  i:=b[i,2];
 end;
end;
procedure dfs2(q:longint);
var i:longint;
begin
 i:=a[q];
 while i>0 do
 begin
  if y[b[i,1]]=-1 then begin if i mod 2=1 then y[b[i,1]]:=y[q]-1 else y[b[i,1]]:=y[q]+1;dfs2(b[i,1]);end;
  i:=b[i,2];
 end;
 if y[q]<z then z:=y[q];
end;
begin
 z:=9999999;
 readln(n);
 for i:=2 to n do
 begin
  readln(k,l);
  b[i*2-1,1]:=k;
  b[i*2-1,2]:=a[l];
  a[l]:=i*2-1;
  b[i*2,1]:=l;
  b[i*2,2]:=a[k];
  a[k]:=i*2;
  y[i]:=-1;
 end;
 k:=0;
 dfs(1);y[1]:=k;
 dfs2(1);
 writeln(z);
 for i:=1 to n do
  if y[i]=z then write(i,' ');
end.