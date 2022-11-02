program code34B;

{$APPTYPE CONSOLE}
{$R+,Q+}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
const hash=997;
var n,m:int;
    a:array[-1..1000]of int;

procedure swap(var a,b:int);
 var c:int;
begin
  c:=a;
  a:=b;
  b:=c
end;

procedure readdata;
 var i:int;
begin
  readln(n,m);
  for i:=1 to n do
    read(a[i]);
end;

procedure qsort(l,r:int);
 var i,j,x:int;
begin
  i:=l;
  j:=r;
  x:=a[(l+r)div 2];
  while i<=j do begin
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if (i<=j)then begin
      swap(a[i],a[j]);
      inc(i);
      dec(j)
    end;
  end;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r)
end;

procedure solve;
 var i,ans:int;
begin
  qsort(1,n);

  i:=1;
  ans:=0;
  while (i<=n)and(i<=m)and(a[i]<0)do begin
    inc(ans,a[i]);
    inc(i);
  end;
  writeln(-ans)
end;

begin
  {$IFNDEF ONLINE_JUDGE}
  reset(input,'input.txt');
  rewrite(output,'output.txt');
  {$ENDIF}
  readdata;
  solve
end.