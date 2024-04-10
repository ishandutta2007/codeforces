var a,b,c:longint;
    r:real;
begin
 readln(a,b,c);
 r:=a*c/100;
 if r>b then begin if frac(r)=0 then writeln(trunc(r-b)) else writeln(trunc(r-b)+1);end else writeln(0);
end.