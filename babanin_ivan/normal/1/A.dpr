program Projecta;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var n,m,a,ans,i,j:int64;
begin
 {reset(input,'input.txt');
 rewrite(output,'output.txt');}
 readln(n,m,a);
 i:=trunc(n/a);
 j:=trunc(m/a);
 if n/a>i then inc(i);
 if m/a>j then inc(j);
 writeln(i*j);
end.