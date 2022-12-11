var a,b:longint;
begin
 readln(a,b);
 if b=0 then writeln(a,' ',a) else if a=0 then writeln('Impossible') else if b>=a then writeln(b,' ',b+a-1) else writeln(a,' ',b+a-1); 
end.