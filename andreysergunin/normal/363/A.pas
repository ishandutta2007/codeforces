var n,m,i:longint;
begin
{assign (input,'input.txt');
assign (output,'output.txt');
reset (input);
rewrite (output) ; }
read (n);
if n=0 then write ('O-|-OOOO');
while n<>0 do
        begin
         m:=n mod 10;
         n:=n div 10;
         if m>=5 then write ('-O|')
                 else write ('O-|');
         for i:=1 to m mod 5 do write ('O');
         write ('-');
         for i:= 1 to 4-m mod 5 do write ('O');
         writeln

        end;


end.