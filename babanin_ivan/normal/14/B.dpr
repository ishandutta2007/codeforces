program code6;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean; 
var a0,a,b,b0:int;

procedure swap(var a,b:int);
 var c:int;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure new;
begin
 if (b0<a)or(b<a0)then begin
  writeln(-1);
  halt(0)
 end;
 if b0>b then b0:=b;
 if a0<a then a0:=a
end;

procedure readdata;
 var i,n,x0:int;
begin
 readln(n,x0);
 readln(a0,b0);
 if a0>b0 then swap(a0,b0);

 for i:=2 to n do begin
  readln(a,b);
  if a>b then swap(a,b);
  new
 end;

 if (x0>=a0)and(x0<=b0)then writeln(0)
  else
   if x0<a0 then writeln(a0-x0)
    else writeln(x0-b0)
end;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input,'input.txt');
 rewrite(output,'output.txt');
 {$ENDIF}
 readdata
end.