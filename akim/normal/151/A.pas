var a,b,c,d,e,f,g,h,x,y,z:longint;
begin
 readln(a,b,c,d,e,f,g,h);
 x:=(b*c)div g;
 y:=d*e;
 z:=f div h;
 if (x<=y)and(x<=z) then begin writeln(x div a);halt(0);end;
 if (y<=x)and(y<=z) then begin writeln(y div a);halt(0);end;
 if (z<=y)and(z<=x) then begin writeln(z div a);halt(0);end;
end.