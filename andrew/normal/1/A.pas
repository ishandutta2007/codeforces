var
 a,b,c,c1,m:extended;
begin
 readln(a,b,m);
 c:=trunc((a+m-1)/m);
 c1:=trunc((b+m-1)/m);
 writeln((c*c1):0:0);
end.