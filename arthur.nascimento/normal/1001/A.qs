namespace Solution {



    open Microsoft.Quantum.Canon;

    open Microsoft.Quantum.Diagnostics;

    open Microsoft.Quantum.Primitive;



    operation Solve (q : Qubit, sign : Int) : ()

    {

        body

        {

            H(q);

            if(sign == -1){

                Z(q);

            }

        }

    }

}