var n,m,k:longint;
   begin
   read(n);
   if n=1 then writeln('0 1') else
   if n=2 then writeln('0 2') else
      begin
      if (n mod 7)=6 then k:=1;
      if ((n-2) mod 7)=6 then m:=1;
      writeln((n div 7)*2+k,' ',2+((n-2) div 7)*2+m);
      end;
   end.