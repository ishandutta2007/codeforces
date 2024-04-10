program code4;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
type int=integer;
var n,k:int;

procedure swap(var a,b:integer);
var c:integer;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure readdata;
begin
 readln(n,k)
end;

procedure solve;
 var i,j,m,sum:int;
     p:array[1..10000]of boolean;
     a,ans:array[0..10000]of int;
     f:boolean;

begin
 for i:=1 to n+100 do p[i]:=true;
 for i:=2 to n+100 do
  if p[i] then begin
   j:=2*i;
   while j<=n+100 do begin
    p[j]:=false;
    inc(j,i)
   end;
  end;
 m:=0;
 for i:=1 to n+100 do
  if p[i] then begin
                inc(m);
                a[m]:=i
               end;
 sum:=0;
 for i:=2 to m do
  ans[i]:=a[i]+a[i-1];
 for i:=2 to m do begin
  if a[i]>n then break;
  f:=false;
  for j:=1 to m-1 do
   if a[i]=(1+ans[j])then f:=true;
  if f then inc(sum);
 end;
 if sum>=k then writeln('YES')
  else writeln('NO')
end;



begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve;

end.