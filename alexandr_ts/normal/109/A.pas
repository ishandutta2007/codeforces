var k,n,i,x,y,j:longint;

    s:string;

begin

 read(n);

 if n=0 then begin write('-1');exit; end;

 for x:=0 to (n div 4) do

   if (n-4*x)mod 7 = 0 then

     begin

       for i:=1 to x do

         s:=s+'4';

       for j:=1 to (n-4*x)div 7 do

         s:=s+'7';

       write(s);

       exit;

     end;

 write('-1');

end.