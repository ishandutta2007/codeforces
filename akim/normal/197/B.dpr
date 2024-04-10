var a,b,c,d,e:longint;
function nod(x,y:longint):longint;
begin
 if x<>0 then nod:=nod(y mod x,x) else nod:=y;
end;
begin
 readln(a,b);readln(c);readln(d);
 if a>b then if c*d>0 then begin writeln('Infinity');halt(0);end else begin writeln('-Infinity');halt(0);end;
 if b>a then begin writeln('0/1');halt(0);end;
 e:=nod(abs(c),abs(d));
 if (c*d<0)then write('-');
 writeln(abs(c) div e,'/',abs(d) div e);
end.