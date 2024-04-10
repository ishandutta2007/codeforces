program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type int=integer;
var a,b:array[0..9]of int;
    s,s1:string;

procedure readdata;
 var i,j:int;
begin
 readln(s);
 for i:=1 to length(s) do
  a[i]:=ord(s[i])-ord('0');   readln(s1);
 for i:=1 to length(s1) do
  b[i]:=ord(s1[i])-ord('0');
end;

procedure swap(var a,b:int);
 var c:int;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure solve;
 var f:boolean;
     n,i,j:int;
begin
 {if (s='0') and (s1='0')then begin
  writeln('OK');
  halt(0)
 end
 else begin
       writeln('WRONG_ANSWER');
       halt(0)
      end;  }
 if length(s)<>length(s1)then begin
  writeln('WRONG_ANSWER');
  halt(0)
 end;
 n:=length(s);
 for i:=1 to n do
  for j:=1 to n do
   if a[j]>a[i] then swap(a[i],a[j]);
 if a[1]=0 then begin
  i:=1;
  while (a[i]=0)and(i<=n) do inc(i);
  swap(a[1],a[i])
 end;
 f:=true;
 for i:=1 to n do
  if a[i]<>b[i] then f:=false;
 if f then writeln('OK')
  else writeln('WRONG_ANSWER');
end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve;
end.