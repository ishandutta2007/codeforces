program code4;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

type int=integer;
     ext=extended;
var a,b,c,d:ext;

procedure swap(var a,b:int);
 var c:int;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure readdata;
begin
 readln(a,b,c);
end;

procedure solve;
begin
 if (a=0)and(b=0)and(c=0)then begin
  writeln(-1);
  halt(0)
 end;
 if (a=0)and(b=0)then begin
  writeln(0);
  halt(0)
 end;
 if (a=0)then begin
  writeln(1);
  writeln(-c/b:0:7);
  halt(0);
 end;
 if b=0 then begin
  if (-c/a)<0 then begin
   writeln(0);
   halt(0)
  end;
  if c=0 then begin
   writeln(1);
   writeln(0);
   halt(0)
  end;
  writeln(2);
  writeln(-sqrt(-c/a):0:7);
  writeln(sqrt(-c/a):0:7);
  halt(0)
 end;
 if c=0 then begin
  writeln(2);
  if -b/a<0 then begin
   writeln(-b/a:0:7);
   writeln(0);
   halt(0)
  end;
  writeln(0);
  writeln(-b/a:0:7);
  halt(0)
 end;
 d:=b*b-4*a*c;
 if d<0 then begin
  writeln(0);
  halt(0)
 end;
 if d=0 then begin
  writeln(1);
  writeln(-b/(2*a):0:7);
  halt(0)
 end;
 writeln(2);
 writeln(min((-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a)):0:7);
 writeln(max((-b-sqrt(d))/(2*a),(-b+sqrt(d))/(2*a)):0:7);
 halt(0)
end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve
end.