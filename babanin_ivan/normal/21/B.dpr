program code5;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

const eps=1e-8;
type ext=extended;
     line=record
      a,b,c:ext;
     end;
     point=record
      x,y:ext;
     end;

var l1,l2:line;
    f:boolean;

function dist(a,b:point):ext;
begin
 dist:=sqrt(sqr(a.x-b.x)+sqr(a.y-b.y))
end;

procedure normline(var l:line);
 var a:ext;
begin
 if l.a<-eps then begin
  l.a:=-l.a;
  l.b:=-l.b;
  l.c:=-l.c
 end
 else if (abs(l.a)<eps)and(l.b<-eps) then begin
                                           l.b:=-l.b;
                                           l.c:=-l.c
                                          end;
 a:=sqrt(sqr(l.a)+sqr(l.b));
 if a<>0 then begin
  l.a:=l.a/a;
  l.b:=l.b/a;
  l.c:=l.c/a
 end;
end;

function crossline(var l1,l2:line):boolean;
begin
 if abs(l1.a*l2.b-l1.b*l2.a)<=eps then begin
  crossline:=false;
  exit
 end;
 crossline:=true;
end;


begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 readln(l1.a,l1.b,l1.c);
 readln(l2.a,l2.b,l2.c);
 if ((l1.a=0)and(l1.b=0)and(l1.c=0))and(not((l2.a=0)and(l2.b=0)and(l2.c<>0)))then begin
  writeln(-1);
  halt(0);
 end;
 if ((l2.a=0)and(l2.b=0)and(l2.c=0))and(not((l1.a=0)and(l1.b=0)and(l1.c<>0)))then begin
  writeln(-1);
  halt(0);
 end;
 if ((l1.a=0)and(l1.b=0)and(l1.c<>0))or((l2.a=0)and(l2.b=0)and(l2.c<>0))then begin
  writeln(0);
  halt(0)
 end;
 if (abs(l1.a-l2.a)<=eps)and(abs(l1.b-l2.b)<=eps)and(abs(l1.c-l2.c)<=eps)then begin
  writeln(-1);
  halt(0)
 end;
 normline(l1);
 normline(l2);
 if (abs(l1.a-l2.a)<=eps)and(abs(l1.b-l2.b)<=eps)and(abs(l1.c-l2.c)<=eps)then begin
  writeln(-1);
  halt(0)
 end;
 f:=crossline(l1,l2);
 if f then writeln(1)
  else writeln(0) 
end.