var a,c:longint;b:real;
begin
 readln(a,b,c);
 if a=1 then begin if c>b then writeln('NO') else writeln('YES');halt(0);end;
 b:=b-c;b:=b*sin(pi/a);
 if b>=c then writeln('YES') else writeln('NO');
end.