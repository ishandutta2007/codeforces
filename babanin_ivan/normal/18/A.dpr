program code4;

{$APPTYPE CONSOLE}
{$minstacksize 16000000}

uses
  SysUtils,Math;
type int=integer;
     ext=extended;
var x1,x2,x3,y3,y2,y1:int64;

procedure swap(var a,b:int64);
 var c:int64;
begin
 c:=a;
 a:=b;
 b:=c
end;

function tre(x1,x2,x3,y1,y2,y3:int64):boolean;
 var f:boolean;
begin
 f:=false;
 if (x1=x2)and(y1=y2)then f:=true;
 if (x1=x3)and(y1=y3)then f:=true;
 if (x3=x2)and(y3=y2)then f:=true;
 tre:=f
end;

procedure readdata;
begin
 readln(x1,y1,x2,y2,x3,y3);
end;

procedure solve;
 var a,b,c:int64;
begin
 a:=sqr(x1-x2)+sqr(y1-y2);
 b:=sqr(x1-x3)+sqr(y1-y3);
 c:=sqr(x3-x2)+sqr(y3-y2);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if (a=b+c)and(not tre(x1,x2,x3,y1,y2,y3))then begin
  writeln('RIGHT');
  halt(0)
 end;

 inc(x1);
 a:=sqr(x1-x2)+sqr(y1-y2);
 b:=sqr(x1-x3)+sqr(y1-y3);
 c:=sqr(x3-x2)+sqr(y3-y2);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if (a=b+c)and(not tre(x1,x2,x3,y1,y2,y3))then begin
  writeln('ALMOST');
  halt(0)
 end;
 dec(x1);
 dec(x1);
 a:=sqr(x1-x2)+sqr(y1-y2);
 b:=sqr(x1-x3)+sqr(y1-y3);
 c:=sqr(x3-x2)+sqr(y3-y2);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if (a=b+c)and(not tre(x1,x2,x3,y1,y2,y3))then begin
  writeln('ALMOST');
  halt(0)
 end;
 inc(x1);

 inc(y1);
 a:=sqr(x1-x2)+sqr(y1-y2);
 b:=sqr(x1-x3)+sqr(y1-y3);
 c:=sqr(x3-x2)+sqr(y3-y2);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if (a=b+c)and(not tre(x1,x2,x3,y1,y2,y3))then begin
  writeln('ALMOST');
  halt(0)
 end;
 dec(y1);
 dec(y1);
 a:=sqr(x1-x2)+sqr(y1-y2);
 b:=sqr(x1-x3)+sqr(y1-y3);
 c:=sqr(x3-x2)+sqr(y3-y2);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if (a=b+c)and(not tre(x1,x2,x3,y1,y2,y3))then begin
  writeln('ALMOST');
  halt(0)
 end;
 inc(y1);

 inc(x2);
 a:=sqr(x1-x2)+sqr(y1-y2);
 b:=sqr(x1-x3)+sqr(y1-y3);
 c:=sqr(x3-x2)+sqr(y3-y2);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if (a=b+c)and(not tre(x1,x2,x3,y1,y2,y3))then begin
  writeln('ALMOST');
  halt(0)
 end;
 dec(x2);
 dec(x2);
 a:=sqr(x1-x2)+sqr(y1-y2);
 b:=sqr(x1-x3)+sqr(y1-y3);
 c:=sqr(x3-x2)+sqr(y3-y2);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if (a=b+c)and(not tre(x1,x2,x3,y1,y2,y3))then begin
  writeln('ALMOST');
  halt(0)
 end;
 inc(x2);

 inc(y2);
 a:=sqr(x1-x2)+sqr(y1-y2);
 b:=sqr(x1-x3)+sqr(y1-y3);
 c:=sqr(x3-x2)+sqr(y3-y2);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if (a=b+c)and(not tre(x1,x2,x3,y1,y2,y3))then begin
  writeln('ALMOST');
  halt(0)
 end;
 dec(y2);
 dec(y2);
 a:=sqr(x1-x2)+sqr(y1-y2);
 b:=sqr(x1-x3)+sqr(y1-y3);
 c:=sqr(x3-x2)+sqr(y3-y2);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if (a=b+c)and(not tre(x1,x2,x3,y1,y2,y3))then begin
  writeln('ALMOST');
  halt(0)
 end;
 inc(y2);

 inc(x3);
 a:=sqr(x1-x2)+sqr(y1-y2);
 b:=sqr(x1-x3)+sqr(y1-y3);
 c:=sqr(x3-x2)+sqr(y3-y2);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if (a=b+c)and(not tre(x1,x2,x3,y1,y2,y3))then begin
  writeln('ALMOST');
  halt(0)
 end;
 dec(x3);
 dec(x3);
 a:=sqr(x1-x2)+sqr(y1-y2);
 b:=sqr(x1-x3)+sqr(y1-y3);
 c:=sqr(x3-x2)+sqr(y3-y2);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if (a=b+c)and(not tre(x1,x2,x3,y1,y2,y3))then begin
  writeln('ALMOST');
  halt(0)
 end;
 inc(x3);

 inc(y3);
 a:=sqr(x1-x2)+sqr(y1-y2);
 b:=sqr(x1-x3)+sqr(y1-y3);
 c:=sqr(x3-x2)+sqr(y3-y2);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if (a=b+c)and(not tre(x1,x2,x3,y1,y2,y3))then begin
  writeln('ALMOST');
  halt(0)
 end;
 dec(y3);
 dec(y3);
 a:=sqr(x1-x2)+sqr(y1-y2);
 b:=sqr(x1-x3)+sqr(y1-y3);
 c:=sqr(x3-x2)+sqr(y3-y2);
 if a<b then swap(a,b);
 if a<c then swap(a,c);
 if (a=b+c)and(not tre(x1,x2,x3,y1,y2,y3))then begin
  writeln('ALMOST');
  halt(0)
 end;
 inc(y3);

 writeln('NEITHER');
end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readdata;
 solve
end.