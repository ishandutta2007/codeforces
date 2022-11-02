program code4;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
type int=integer;
     ext=extended;
var s:string;

procedure swap(var a,b:int);
 var c:int;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure readdata;
begin
 readln(s)
end;

procedure writeno;
begin
 writeln('NO');
 halt(0);
end;

procedure solve;
 var i,j,x,n:int;
     a:array[-1..1000]of int;
     f:boolean;
begin
 i:=1;
 j:=1;
 if s[1]='@'then writeno;
 while (s[i]<>'@')and(i<=length(s))do inc(i);
 if s[i]<>'@' then writeno;
 dec(i);
 if i>16 then writeno;
 for x:=j to i do
  if not(
   ((ord(s[x])>=ord('a'))and(ord(s[x])<=ord('z')))or
   ((ord(s[x])>=ord('A'))and(ord(s[x])<=ord('Z')))or
   ((ord(s[x])>=ord('0'))and(ord(s[x])<=ord('9')))or
   (ord(s[x])=ord('_')))then writeno;


 j:=i+2;
 inc(i);
 inc(i);
 while (s[i]<>'/')and(i<=length(s))do inc(i);
 f:=false;
 if s[i]<>'/' then f:=true;
 dec(i);
 if (i-j+1>32)or(i-j+1<1)then writeno;
 if (s[j]='.')then writeno;
 n:=0;
 //a[1]:=j; }
 for x:=j+1 to i do
  if (s[x]='.')then begin
   inc(n);
   a[n]:=x
  end;
 {inc(n);
 a[n]:=i; }
 for x:=2 to n do
  if (a[x]-a[x-1]-1>16)or(a[x]-a[x-1]-1<1)then writeno;
 if n<>0 then begin
  if (a[1]-j>16)or(a[1]-j<1)then writeno;
  if (i-a[n]>16)or(i-a[n]<1)then writeno
 end;
 for x:=j to i do
  if not(
   ((ord(s[x])>=ord('a'))and(ord(s[x])<=ord('z')))or
   ((ord(s[x])>=ord('A'))and(ord(s[x])<=ord('Z')))or
   ((ord(s[x])>=ord('0'))and(ord(s[x])<=ord('9')))or
   (ord(s[x])=ord('_'))or(ord(s[x])=ord('.')))then writeno;

 if f then begin
  writeln('YES');
  halt(0)
 end;
 j:=i+2;
 i:=i+2;
 if i>length(s) then writeno;
 while(i<=length(s))do inc(i);
 dec(i);

 if ((i-j+1)>16)or(s[i]='/') then writeno;
 for x:=j to i do
  if not(
   ((ord(s[x])>=ord('a'))and(ord(s[x])<=ord('z')))or
   ((ord(s[x])>=ord('A'))and(ord(s[x])<=ord('Z')))or
   ((ord(s[x])>=ord('0'))and(ord(s[x])<=ord('9')))or
   (ord(s[x])=ord('_')))then writeno;
 writeln('YES');
  halt(0)
end;



begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve
end.